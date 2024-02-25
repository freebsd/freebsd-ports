PORTNAME=	jwhois
PORTVERSION=	4.0
PORTREVISION=	9
CATEGORIES=	net
MASTER_SITES=	GNU \
		https://dl.fedoraproject.org/pub/fedora/linux/development/rawhide/Everything/source/tree/Packages/j/:srpm
DISTFILES=	${DISTNAME}.tar.gz jwhois-4.0-73.fc38.src.rpm:srpm

MAINTAINER=	terry-freebsd@glaver.org
COMMENT=	Improved WHOIS client capable of selecting server to query
WWW=		https://www.gnu.org/software/jwhois/

LICENSE=	GPLv3

RUN_DEPENDS=	lynx:www/lynx
LIB_DEPENDS=	libidn.so:dns/libidn

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USES=		gettext gmake iconv
CPPFLAGS+=	-I${PREFIX}/include
LDFLAGS+=	-L${PREFIX}/lib
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/var/jwhois

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_OFF=	--disable-nls \
			--without-libiconv-prefix

INSTALL_TARGET=	install-strip

INFO=		jwhois

.include <bsd.port.pre.mk>

JWHOIS_CONF_SRC=	${WRKDIR}/jwhois.conf

pre-patch:
.for p in jwhois-4.0-connect.patch jwhois-4.0-ipv6match.patch jwhois-4.0-fclose.patch \
		jwhois-4.0-select.patch jwhois-4.0-multi-homed.patch jwhois-4.0-libidn2.patch \
		jwhois-4.0-idna.patch jwhois-4.0-idnfail.patch jwhois-4.0-ipv4_ipv6.patch \
		jwhois-configure-c99.patch jwhois-c99.patch
	(cd ${WRKSRC} && ${PATCH} -p1 <  ${WRKDIR}/${p})
.endfor

post-patch:
	${REINPLACE_CMD} 's|browser-pathname = "/usr/bin|browser-pathname = "${LOCALBASE}/bin|' \
		${WRKDIR}/jwhois.conf

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/var/jwhois
	${INSTALL_DATA} ${JWHOIS_CONF_SRC} ${STAGEDIR}${PREFIX}/etc/jwhois.conf.sample

.include <bsd.port.post.mk>
