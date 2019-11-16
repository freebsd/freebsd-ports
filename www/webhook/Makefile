# $FreeBSD$

PORTNAME=	webhook
PORTVERSION=	2.6.9
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	stb@lassitu.de
COMMENT=	Easily create HTTP endpoints (hooks) to execute shell commands

LICENSE=	APACHE20 BSD3CLAUSE MIT
LICENSE_COMB=	multi

USES=		go
GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
USE_GITHUB=	yes
GH_ACCOUNT=	adnanh
USE_RC_SUBR=	webhook

GO_TARGET=	:${PREFIX}/sbin/webhook

PLIST_FILES=	"@sample etc/webhook.yaml.sample" sbin/webhook

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
DAEMONARGS=	-S -l \$${webhook_facility} -s \$${webhook_priority} -t \$${name}
.else
DAEMONARGS=	-f
.endif

SUB_LIST+=	DAEMONARGS="${DAEMONARGS}"

post-install:
	${INSTALL_DATA}  ${FILESDIR}/webhook.yaml ${STAGEDIR}${PREFIX}/etc/webhook.yaml.sample

.include <bsd.port.mk>
