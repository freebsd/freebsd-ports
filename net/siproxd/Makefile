# Created by: Frank W. Josellis <frank@dynamical-systems.org>
# $FreeBSD$

PORTNAME=	siproxd
PORTVERSION=	0.8.2
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	frank@dynamical-systems.org
COMMENT=	Proxy/masquerading daemon for the SIP protocol

LICENSE=	GPLv2

LIB_DEPENDS=	libosip2.so:net/libosip2

# :keepla because port uses lt_dlopen
USES=		libtool:keepla
USE_RC_SUBR=	siproxd
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-doc --disable-static --with-libosip-prefix=${PREFIX}
INSTALL_TARGET=	install-strip

PORTDOCS1=	AUTHORS ChangeLog README RELNOTES
PORTDOCS2=	FAQ KNOWN_BUGS RFC3261_compliance.txt \
		sample_cfg_budgetone.txt sample_cfg_x-lite.txt
PORTDOCS=	${PORTDOCS1} ${PORTDOCS2}

post-extract:
.for docs in ${PORTDOCS2}
	${CP} ${WRKSRC}/doc/${docs} ${WRKSRC}
.endfor

post-patch:
	${REINPLACE_CMD} -e 's,siproxd\.conf\.example,siproxd.conf.sample,g' \
		${WRKSRC}/doc/Makefile.in
	${MV} ${WRKSRC}/doc/siproxd.conf.example ${WRKSRC}/doc/siproxd.conf.sample

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docs in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${docs} ${STAGEDIR}${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/siproxd_passwd.cfg \
		${STAGEDIR}${PREFIX}/etc/siproxd_passwd.cfg.sample

.include <bsd.port.mk>
