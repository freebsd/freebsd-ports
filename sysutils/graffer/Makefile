PORTNAME=	graffer
DISTVERSION=	1.5.1
CATEGORIES=	sysutils
MASTER_SITES=	http://chaosophia.net/downloads/graffer/

MAINTAINER=	koue@chaosophia.net
COMMENT=	Utility to collect and render graphical statistics
WWW=		http://chaosophia.net/graffer/

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libpng.so:graphics/png

post-patch:
	@${REINPLACE_CMD} -e "s|/etc/graffer/|${ETCDIR}/|; \
			s|/etc/graffer.conf|${ETCDIR}/graffer.conf|" \
		${WRKSRC}/src/graffer.[c8] ${WRKSRC}/etc/graffer.conf.example

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/graffer ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/src/graffer.8 ${STAGEDIR}${PREFIX}/share/man/man8
	(cd ${WRKSRC}/etc/conf.d && ${COPYTREE_SHARE} . ${STAGEDIR}${ETCDIR}/conf.d.sample)
	(cd ${WRKSRC}/scripts && ${COPYTREE_BIN} . ${STAGEDIR}${ETCDIR}/scripts.sample \
		' ! -name README ')
	${INSTALL_DATA} ${WRKSRC}/scripts/README ${STAGEDIR}${ETCDIR}/scripts.sample
	${INSTALL_DATA} ${WRKSRC}/etc/graffer.conf.example ${STAGEDIR}${ETCDIR}/graffer.conf.sample

.include <bsd.port.mk>
