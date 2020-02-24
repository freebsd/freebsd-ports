# $FreeBSD$

PORTNAME=	webhook
PORTVERSION=	2.6.9
PORTREVISION=	2
CATEGORIES=	www

MAINTAINER=	stb@lassitu.de
COMMENT=	Easily create HTTP endpoints (hooks) to execute shell commands

LICENSE=	APACHE20 BSD3CLAUSE MIT
LICENSE_COMB=	multi

USES=		go
GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
USE_GITHUB=	yes
GH_ACCOUNT=	adnanh
GH_TUPLE=	golang:sys:fead79001313:golang_sys/vendor/golang.org/x/sys_fead79001313
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

pre-build:
	${RM} -r ${WRKSRC}/vendor/golang.org/x/sys
	${MV} ${WRKSRC}/vendor/golang.org/x/sys_fead79001313 ${WRKSRC}/vendor/golang.org/x/sys

post-install:
	${INSTALL_DATA}  ${FILESDIR}/webhook.yaml ${STAGEDIR}${PREFIX}/etc/webhook.yaml.sample

.include <bsd.port.mk>
