# New ports collection makefile for:	sentinel
# Date created:		14 May 2002
# Whom:			Peter Hollaubek <fifteen@inext.hu>
#
# $FreeBSD$
#

PORTNAME=	sentinel
PORTVERSION=	1.6.1b
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	smfilter

MAINTAINER=	ports@FreeBSD.org

USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e \
		's|:/var|:${PREFIX}/var|g' ${WRKSRC}/sentinel.cf.SAMPLE

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${PTHREAD_CFLAGS} -o ${PORTNAME} \
		${PORTNAME}.c -lmilter ${PTHREAD_LIBS} 

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sentinel ${PREFIX}/sbin
	@${MKDIR} ${PREFIX}/var/sentinel
	${CHOWN} smmsp:smmsp ${PREFIX}/var/sentinel
	${INSTALL_SCRIPT} ${FILESDIR}/000.sentinel.sh ${PREFIX}/etc/rc.d
	${INSTALL_DATA} ${WRKSRC}/sentinel.cf.SAMPLE ${PREFIX}/etc/sentinel.cf.dist
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
