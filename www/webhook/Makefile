PORTNAME=	webhook
PORTVERSION=	2.8.0
PORTREVISION=	16
CATEGORIES=	www

MAINTAINER=	stb@lassitu.de
COMMENT=	Easily create HTTP endpoints (hooks) to execute shell commands
WWW=		https://github.com/adnanh/webhook

LICENSE=	APACHE20 BSD3CLAUSE MIT
LICENSE_COMB=	multi

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	adnanh
GH_TUPLE=	golang:sys:v0.5.0:golang_sys/vendor/golang.org/x/sys_

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

pre-patch:
	${RM} -r ${WRKSRC}/vendor/golang.org/x/sys
	${MV} ${WRKSRC}/vendor/golang.org/x/sys_ ${WRKSRC}/vendor/golang.org/x/sys

post-install:
	${INSTALL_DATA}  ${FILESDIR}/webhook.yaml ${STAGEDIR}${PREFIX}/etc/webhook.yaml.sample

.include <bsd.port.mk>
