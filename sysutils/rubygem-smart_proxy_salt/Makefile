PORTNAME=	smart_proxy_salt
PORTVERSION=	5.0.0
CATEGORIES=	sysutils ruby
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	SaltStack Plug-In for Foreman's Smart Proxy

LICENSE=	GPLv3

RUN_DEPENDS=	foreman-proxy>=1.8.0:net/foreman-proxy \
		${PYTHON_PKGNAMEPREFIX}salt>0:sysutils/py-salt@${PY_FLAVOR} \
		rubygem-smart_proxy_dynflow>=0.5.0:sysutils/rubygem-smart_proxy_dynflow

USES=		cpe gem python shebangfix
USE_RUBY=	yes

NO_ARCH=	yes

CPE_VENDOR=	theforeman

SHEBANG_FILES=	bin/foreman-node \
		sbin/upload-salt-reports
python_OLD_CMD=	/usr/bin/salt_python_wrapper

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/bin/foreman-node ${WRKSRC}/sbin/upload-salt-reports

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/foreman-proxy/settings.d ${STAGEDIR}${PREFIX}/etc/salt ${STAGEDIR}${PREFIX}/share/foreman-proxy/bundler.d
	${INSTALL_DATA} ${WRKSRC}/settings.d/salt.yml.example ${STAGEDIR}${PREFIX}/etc/foreman-proxy/settings.d/salt.yml.sample
	${INSTALL_DATA} ${WRKSRC}/etc/foreman.yaml.example ${STAGEDIR}${PREFIX}/etc/salt/foreman.yaml.sample
	${INSTALL_SCRIPT} ${WRKSRC}/sbin/upload-salt-reports ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${FILESDIR}/salt.rb ${STAGEDIR}${PREFIX}/share/foreman-proxy/bundler.d/salt.rb

.include <bsd.port.mk>
