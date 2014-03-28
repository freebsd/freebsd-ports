# Created by: Frank W. Josellis <frank@dynamical-systems.org>
# $FreeBSD$

PORTNAME=	siproxd
PORTVERSION=	0.7.2
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	frank@dynamical-systems.org
COMMENT=	A proxy/masquerading daemon for the SIP protocol

LICENSE=	GPLv2

LIB_DEPENDS=	libosip2.so:${PORTSDIR}/net/libosip

USE_RC_SUBR=	siproxd
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-doc --with-libosip-prefix=${PREFIX}

PORTDOCS1=	AUTHORS ChangeLog README RELNOTES
PORTDOCS2=	FAQ KNOWN_BUGS RFC3261_compliance.txt \
		sample_cfg_budgetone.txt sample_cfg_x-lite.txt
PORTDOCS=	${PORTDOCS1} ${PORTDOCS2}

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,-lgnugetopt,,g ; 24600d ; 23998s,doc/Makefile ,,g' ${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' \
	${WRKSRC}/doc/siproxd.conf.example
	${REINPLACE_CMD} -e '22s,doc ,,' ${WRKSRC}/Makefile.am
	${REINPLACE_CMD} -e '212s,doc ,,' ${WRKSRC}/Makefile.in

post-extract:
.for docs in ${PORTDOCS2}
	${CP} ${WRKSRC}/doc/${docs} ${WRKSRC}
.endfor

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docs in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${docs} ${STAGEDIR}${DOCSDIR}
.endfor
	${CP} ${WRKSRC}/doc/siproxd.conf.example ${STAGEDIR}${PREFIX}/etc
	${CP} ${WRKSRC}/doc/siproxd_passwd.cfg ${STAGEDIR}${PREFIX}/etc
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/siproxd/plugin_defaulttarget.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/siproxd/plugin_demo.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/siproxd/plugin_fix_bogus_via.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/siproxd/plugin_logcall.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/siproxd/plugin_shortdial.so

.include <bsd.port.post.mk>
