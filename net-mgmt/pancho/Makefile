# $FreeBSD$

PORTNAME=	pancho
PORTVERSION=	9.3.9
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.pancho.org/archives/pancho/ \
		http://200ok.org/distfiles/pancho/
DISTNAME=	pancho-v${PORTVERSION}

MAINTAINER=	ecu@200ok.org
COMMENT=	Network devices management tool using TFTP and SNMP

RUN_DEPENDS=	p5-Net-SNMP>=0:net-mgmt/p5-Net-SNMP \
		p5-Config-IniFiles>=0:devel/p5-Config-IniFiles \
		p5-Parallel-ForkManager>=0:devel/p5-Parallel-ForkManager

WRKSRC=		${WRKDIR}/Pancho-${PORTVERSION}
USES=		perl5
USE_PERL5=	configure

DOCS=		README README.plugins Plugin.sample

OPTIONS_DEFINE=	DOCS

post-patch:
	@${MV} ${WRKSRC}/lib/Pancho/Plugins/README ${WRKSRC}/README.plugins
	@${MV} ${WRKSRC}/lib/Pancho/Plugins/Plugin.sample ${WRKSRC}/

post-install:
	${INSTALL_DATA} ${WRKSRC}/samples/sample.conf ${STAGEDIR}${PREFIX}/etc/pancho.conf.sample
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
