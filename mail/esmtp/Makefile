# New ports collection makefile for:  		esmtp
# Date created:        				12.07.2003
# Whom:               				Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	esmtp
PORTVERSION=	1.2
CATEGORIES=	mail
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Relay-only Mail Transfer Agent with sendmail compatible syntax

LIB_DEPENDS=	esmtp.6:${PORTSDIR}/mail/libesmtp

LICENSE=	GPLv2

USE_BZIP2=	yes
USE_OPENSSL=	yes
USE_BISON=	build
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		esmtp.1
MAN5=		esmtprc.5
PORTDOCS=	README
PLIST_FILES=	bin/esmtp etc/esmtprc.sample

SUB_FILES=	pkg-message

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

post-patch:
.for file in ${PORTNAME}.1
	@${REINPLACE_CMD} -e \
		's|^/etc|${PREFIX}/etc|g' ${WRKSRC}/${file}
.endfor
.for file in esmtprc.5 sample.esmtprc
	@${REINPLACE_CMD} -e \
		's|/usr/bin/|${LOCALBASE}/bin/|g ; \
		 s|/usr/lib/|/usr/libexec/|g' ${WRKSRC}/${file}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/esmtprc.5 ${MAN5PREFIX}/man/man5
	${INSTALL_DATA} ${WRKSRC}/sample.esmtprc \
		${PREFIX}/etc/esmtprc.sample
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
