# ex:ts=8
# New ports collection makefile for:   	centericq
# Date created:                        	25 December 1999
# Whom:                                 Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	centericq
PORTVERSION=	4.5.0
CATEGORIES=	net
MASTER_SITES=	http://konst.org.ua/download/

MAINTAINER=	ijliao@FreeBSD.org

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext \
		sigc.1:${PORTSDIR}/devel/libsigc++

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lintl"
CONFIGURE_ARGS=	--without-included-gettext

MAN1=	centericq.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400010
LIB_DEPENDS+=	ncurses.5:${PORTSDIR}/devel/ncurses
CFLAGS+=	-nostdinc -I${LOCALBASE}/include/ncurses \
		-I${LOCALBASE}/include -I/usr/include
.endif

post-patch:
	@${PERL} -pi -e "s,\@mandir\@,\@mandir\@/man1,g ; \
		s,\$\(pkgdatadir\),\$\(mandir\),g ; \
		s,intl,,g" ${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
