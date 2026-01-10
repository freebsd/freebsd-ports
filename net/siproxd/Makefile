PORTNAME=	siproxd
DISTVERSION=	0.8.3
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	siva@FreeBSD.org
COMMENT=	Proxy/masquerading daemon for the SIP protocol
WWW=		http://siproxd.sourceforge.net/

LICENSE=	GPLv2

LIB_DEPENDS=	libosip2.so:net/libosip2

# :keepla because port uses lt_dlopen
USES=		libtool:keepla sqlite
USE_RC_SUBR=	siproxd
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-doc --disable-static --with-libosip-prefix=${PREFIX}
INSTALL_TARGET=	install-strip

PORTDOCS1=	AUTHORS ChangeLog README RELNOTES
PORTDOCS2=	FAQ KNOWN_BUGS RFC3261_compliance.txt \
		sample_cfg_budgetone.txt sample_cfg_x-lite.txt
PORTDOCS=	${PORTDOCS1} ${PORTDOCS2}

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e 's,siproxd\.conf\.example,siproxd.conf.sample,g' \
		${WRKSRC}/doc/Makefile.in
	${MV} ${WRKSRC}/doc/siproxd.conf.example ${WRKSRC}/doc/siproxd.conf.sample

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/siproxd_passwd.cfg \
		${STAGEDIR}${PREFIX}/etc/siproxd_passwd.cfg.sample

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for d in ${PORTDOCS1}
	${INSTALL_DATA} ${WRKSRC}/${d} ${STAGEDIR}${DOCSDIR}
.endfor
.for d in ${PORTDOCS2}
	${INSTALL_DATA} ${WRKSRC}/doc/${d} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
