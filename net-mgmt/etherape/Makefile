PORTNAME=	etherape
DISTVERSION=	0.9.22
CATEGORIES=	net-mgmt gnome
MASTER_SITES=	SF

MAINTAINER=	dnpowers@me.com
COMMENT=	Graphical network traffic monitor tool modeled after Etherman
WWW=		http://etherape.sourceforge.net/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool \
		yelp-tools>=0:textproc/yelp-tools
LIB_DEPENDS=	libpopt.so:devel/popt

USES=		gettext-runtime gmake gnome iconv localbase pkgconfig
USE_GNOME=	atk cairo gdkpixbuf gtk30 pango

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	pcap_CFLAGS="-I/usr/include" \
		pcap_LIBS="-lpcap"
LDFLAGS+=	-L/usr/lib
PORTDOCS=	AUTHORS ChangeLog FAQ NEWS README README.bugs TODO

OPTIONS_DEFINE=		DOCS NLS
OPTIONS_SUB=		yes
DOCS_MAKE_ARGS_OFF=	SUBDIRS="src glade m4 po"
NLS_USES=		gettext-tools
NLS_CONFIGURE_ENABLE=	nls

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
