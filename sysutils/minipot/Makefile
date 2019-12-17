# $FreeBSD$

PORTNAME=	minipot
PORTVERSION=	0.2.1
CATEGORIES=	sysutils

MAINTAINER=	pizzamig@FreeBSD.org
COMMENT=	Mono-server installation of pot, nomad and consul

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	pot:sysutils/pot \
	nomad:sysutils/nomad \
	${LOCALBASE}/libexec/nomad/plugins/nomad-pot-driver:sysutils/nomad-pot-driver \
	consul:sysutils/consul \
	traefik:net/traefik

USE_GITHUB=	yes
GH_ACCOUNT=	pizzamig
NO_BUILD=	yes
NO_ARCH=	yes

OPTIONS_DEFINE=	CACERTS EXAMPLES
OPTIONS_DEFAULT=	CACERTS EXAMPLES

CACERTS_DESC	=	Install Certification authorities certificates
CACERTS_RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

PORTEXAMPLES=	*

do-install:
	${MKDIR} ${STAGEDIR}${LOCALBASE}/etc/consul.d
	${MKDIR} ${STAGEDIR}${LOCALBASE}/etc/nomad
	${MKDIR} ${STAGEDIR}${LOCALBASE}/etc/syslog.d
	${MKDIR} ${STAGEDIR}${LOCALBASE}/etc/newsyslog.conf.d
	${MKDIR} ${STAGEDIR}${LOCALBASE}/etc/cron.d

	${INSTALL_DATA} ${WRKSRC}/etc/consul.d/minipot-agent.json \
		${STAGEDIR}${LOCALBASE}/etc/consul.d/minipot-agent.json
	${INSTALL_DATA} ${WRKSRC}/etc/nomad/minipot-server.hcl.sample \
		${STAGEDIR}${LOCALBASE}/etc/nomad/minipot-server.hcl.sample
	${INSTALL_DATA} ${WRKSRC}/etc/minipot-traefik.toml.sample \
		${STAGEDIR}${LOCALBASE}/etc/minipot-traefik.toml.sample
	${INSTALL_DATA} ${WRKSRC}/etc/syslog.d/*.conf \
		${STAGEDIR}${LOCALBASE}/etc/syslog.d
	${INSTALL_DATA} ${WRKSRC}/etc/newsyslog.conf.d/*.conf \
		${STAGEDIR}${LOCALBASE}/etc/newsyslog.conf.d
	${INSTALL_DATA} ${WRKSRC}/etc/cron.d/* \
		${STAGEDIR}${LOCALBASE}/etc/cron.d
	${INSTALL_SCRIPT} ${WRKSRC}/bin/minipot-init \
		${STAGEDIR}${LOCALBASE}/bin/minipot-init
	${INSTALL_SCRIPT} ${WRKSRC}/bin/minipot-start \
		${STAGEDIR}${LOCALBASE}/bin/minipot-start

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/share/examples/${PORTNAME}/* \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
