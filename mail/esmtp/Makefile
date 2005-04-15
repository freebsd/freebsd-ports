# New ports collection makefile for:  		esmtp
# Date created:        				12.07.2003
# Whom:               				Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	esmtp
PORTVERSION=	0.5.1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Relay-only Mail Transfer Agent with sendmail compatible syntax

LIB_DEPENDS=	esmtp.6:${PORTSDIR}/mail/libesmtp

USE_BZIP2=	yes
USE_OPENSSL=	yes
USE_BISON=	yes
USE_GETOPT_LONG=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		esmtp.1
MAN5=		esmtprc.5
PORTDOCS=	README
PLIST_FILES=	bin/esmtp etc/esmtprc.sample

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin|${LOCALBASE}/bin|g' \
		${WRKSRC}/sample.esmtprc
	@${REINPLACE_CMD} -e 's|sendmail(1)|sendmail(8)|g ; \
		s|/etc|${PREFIX}/etc|g' ${WRKSRC}/${PORTNAME}.1
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|g' \
		${WRKSRC}/parser.c ${WRKSRC}/parser.y

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/esmtprc.5 ${MANPREFIX}/man/man5
	${INSTALL_DATA} ${WRKSRC}/sample.esmtprc \
		${PREFIX}/etc/esmtprc.sample
	@${ECHO_MSG} "------------------------------------------------------------"
	@${ECHO_MSG} "Sample of configuration file placed at"
	@${ECHO_MSG} "${PREFIX}/etc/esmtprc.sample"
	@${ECHO_MSG} "------------------------------------------------------------"

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
