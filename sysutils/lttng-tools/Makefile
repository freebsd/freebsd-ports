PORTNAME=	lttng-tools
PORTVERSION=	2.9.3
PORTREVISION=	8
CATEGORIES=	sysutils
MASTER_SITES=	http://lttng.org/files/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Set of tools to control LTTng tracing

LICENSE=		LGPL21 GPLv2
LICENSE_COMB=		dual
LICENSE_FILE_LGPL21=	${WRKSRC}/lgpl-2.1.txt
LICENSE_FILE_GPLv2=	${WRKSRC}/gpl-2.0.txt

BROKEN_FreeBSD_13=	ld: error: duplicate symbol: mi_lttng_element_load_override_url
BROKEN_FreeBSD_14=	ld: error: duplicate symbol: mi_lttng_element_load_override_url

LIB_DEPENDS=	libpopt.so:devel/popt \
		liburcu.so:sysutils/liburcu \
		liblttng-ust-ctl.so:sysutils/lttng-ust

USES=		autoreconf bison compiler:c11 gnome libtool localbase pathfix \
		pkgconfig shebangfix tar:bzip2
USE_LDCONFIG=	yes
USE_GNOME=	libxml2

GNU_CONFIGURE=		yes
CONFIGURE_ARGS=	--with-lttng-ust-prefix=${LOCALBASE} \
		--disable-maintainer-mode
INSTALL_TARGET=		install-strip

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/man/*.1 ${STAGEDIR}${MANPREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/doc/man/*.3 ${STAGEDIR}${MANPREFIX}/man/man3/
	${INSTALL_MAN} ${WRKSRC}/doc/man/*.8 ${STAGEDIR}${MANPREFIX}/man/man8/

.include <bsd.port.mk>
