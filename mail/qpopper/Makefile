# New ports collection makefile for:	qpopper
# Date created:				Di  18 Jul 2000 22:36:34 CEST
# Whom:					alex
#
# $FreeBSD$
#

PORTNAME=	qpopper
PORTVERSION= 	3.1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.qualcomm.com/eudora/servers/unix/popper/ \
		ftp://ftp.gmxuk.net/pub/qpopper/ \
		ftp://sunsite.doc.ic.ac.uk/Mirrors/ftp.qualcomm.com/eudora/servers/unix/popper/ \
		ftp://ftp.kracked.com/pub/qpopper/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-lmd -lutil"
CONFIGURE_ARGS=	--enable-apop=${PREFIX}/etc/qpopper/pop.auth \
		--enable-nonauth-file=/etc/ftpusers \
		--enable-bulldb --enable-keep-temp-drop

# Set FULL_POPD_DEBUG for debug-mode. See also -d option to popper
.if defined(FULL_POPD_DEBUG)
CONFIGURE_ARGS+=--enable-debugging
.endif

MAN8=		popauth.8 qpopper.8

post-patch:
	@${PERL} -pi -e "s|!!PREFIX!!|${PREFIX}|g" ${WRKSRC}/man/*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/popper/popauth ${PREFIX}/bin/popauth
	${LN} -sf popauth ${PREFIX}/bin/apopauth
	${INSTALL_PROGRAM} ${WRKSRC}/popper/popper ${PREFIX}/libexec/qpopper
	${INSTALL_MAN} ${WRKSRC}/man/popauth.8 ${PREFIX}/man/man8/popauth.8
	${INSTALL_MAN} ${WRKSRC}/man/popper.8 ${PREFIX}/man/man8/qpopper.8
	@${SED} -e "s:/usr/local:${PREFIX}:" ${PKGMESSAGE}

.include <bsd.port.mk>
