# New ports collection makefile for:   slrn
# Date created:        28 March 1997
# Whom:                Carey Jones <mcj@acquiesce.org>
#
# $FreeBSD$
#

PORTNAME=	slrn
PORTVERSION=	0.9.7.3
PORTREVISION=	1
CATEGORIES=	news ipv6
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	petef@FreeBSD.org

LIB_DEPENDS=	slang.1:${PORTSDIR}/devel/libslang

USE_GMAKE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-ipv6 --disable-inews --with-slrnpull

.if !defined(WITHOUT_SSL)
USE_OPENSSL=	YES
CONFIGURE_ARGS+=	--with-ssl
.endif

ALL_TARGET=	all

MAN1=		slrn.1 slrnpull.1

post-patch:
	@${PERL} -pi -e 's,/usr/lib/sendmail,/usr/sbin/sendmail,' \
		${WRKSRC}/src/slrnfeat.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/slrn ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/slrnpull ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/examples/slrn
	${INSTALL_DATA} ${WRKSRC}/doc/slrn.rc ${PREFIX}/share/examples/slrn
	@${MKDIR} ${PREFIX}/share/examples/slrn/slrnpull
.for file in FAQ README SETUP score slrn.rc slrnpull.conf slrnpull.sh
	${INSTALL_DATA} ${WRKSRC}/doc/slrnpull/${file} ${PREFIX}/share/examples/slrn/slrnpull
.endfor
	${INSTALL_MAN} ${WRKSRC}/doc/slrn.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/slrnpull.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
