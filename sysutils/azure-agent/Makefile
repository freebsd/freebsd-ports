# $FreeBSD$

PORTNAME=	azure-agent
PORTVERSION=	2.2.14
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	honzhan@microsoft.com
COMMENT=	Microsoft Azure Linux Agent

LICENSE=	APACHE20

RUN_DEPENDS=	python:lang/python \
		sudo:security/sudo \
		bash:shells/bash \
		base64:converters/base64 \
		dmidecode:sysutils/dmidecode \
		${PYTHON_PKGNAMEPREFIX}pyasn1>=0:devel/py-pyasn1 \
		${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

NO_BUILD=	yes
USES=		python:2 shebangfix

SHEBANG_FILES=	bin/waagent bin/waagent2.0
python_OLD_CMD=	"/usr/bin/env python"

USE_GITHUB=	yes
GH_ACCOUNT=	Azure
GH_PROJECT=	WALinuxAgent
USE_PYTHON=	autoplist distutils

post-patch:
	${REINPLACE_CMD} -e "s,/usr/sbin/waagent,${PREFIX}/sbin/waagent,g" \
		${WRKSRC}/bin/waagent2.0
	${REINPLACE_CMD} -e "s,/usr/sbin,${PREFIX}/sbin/,g" \
		${WRKSRC}/init/waagent ${WRKSRC}/init/waagent.service \
		${WRKSRC}/setup.py
	${REINPLACE_CMD} -e "s,/etc,${PREFIX}/etc,g" \
			 -e "/set_conf_files.*freebsd\/waagent.conf/ s/^/#/" \
		${WRKSRC}/setup.py
	${REINPLACE_CMD} -e "s,/etc/waagent,${PREFIX}/etc/waagent,g" \
		${WRKSRC}/bin/waagent2.0 \
		${WRKSRC}/azurelinuxagent/common/osutil/default.py \
		${WRKSRC}/init/waagent.service
	${REINPLACE_CMD} -e "s,/etc/rc.d/waagent,${PREFIX}/etc/rc.d/waagent,g" \
		${WRKSRC}/bin/waagent2.0
	${REINPLACE_CMD} -e "s,/usr/bin/python,${PREFIX}/bin/python,g" \
		${WRKSRC}/init/waagent.service
	${REINPLACE_CMD} -e "s,:/usr/local/bin,:/usr/local/bin:/usr/local/sbin,g" \
		${WRKSRC}/init/freebsd/waagent

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/config/freebsd/waagent.conf \
		${STAGEDIR}${PREFIX}/etc/waagent.conf.sample

.include <bsd.port.mk>
