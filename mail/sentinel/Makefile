# New ports collection makefile for:	sentinel
# Date created:		14 May 2002
# Whom:			Peter Hollaubek <fifteen@inext.hu>
#
# $FreeBSD$
#

PORTNAME=	sentinel
PORTVERSION=	1.7b
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	smfilter

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A sendmail milter API implementation

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre

.include <bsd.port.pre.mk>

.if !exists(/usr/lib/libmilter.a) && !exists(${LOCALBASE}/lib/libmilter.a)
IGNORE=		requires Sendmail 8.12
.endif
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.if defined(WITHOUT_SENTINEL_DECODE_SUBJECT)
CFLAGS+=	-DDO_NOT_DECODE_SUBJECT
.endif

do-build:
	cd ${WRKSRC} && \
		${CC} ${CFLAGS} ${PTHREAD_CFLAGS} \
		-o ${PORTNAME} ${PORTNAME}.c ${LDFLAGS} \
		-lmilter -lpcre -lpcreposix ${PTHREAD_LIBS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sentinel ${PREFIX}/sbin
	@${MKDIR} /var/spool/sentinel
	${CHOWN} smmsp:smmsp /var/spool/sentinel
	${INSTALL_DATA} ${FILESDIR}/000.sentinel.sh ${PREFIX}/etc/rc.d/sentinel.sh-dist
	${INSTALL_DATA} ${WRKSRC}/sentinel.cf.SAMPLE ${PREFIX}/etc/sentinel.cf.dist
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.FreeBSD ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
