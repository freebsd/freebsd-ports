PORTNAME=	spf-tools
DISTVERSIONPREFIX=	v
DISTVERSION=	2.3
CATEGORIES=	mail dns

MAINTAINER=	ports@brtsvcs.net
COMMENT=	Shell tools for keeping SPF records tidy
WWW=		https://github.com/spf-tools/spf-tools

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	iprange:net-mgmt/iprange \
		jq:textproc/jq

USE_GITHUB=	yes

NO_ARCH=	yes
NO_BUILD=	yes

_LIBEXECDIR=	${PREFIX}/libexec/${PORTNAME}

_REINPLACE=	cloudflare.sh compare.sh despf.sh dnsimple.sh mkblocks.sh \
		route53.sh runspftools.sh

post-patch:
.for i in ${_REINPLACE}
	@${REINPLACE_CMD} -e 's|.BINDIR/include|${_LIBEXECDIR}|g' ${WRKSRC}/$i
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/*.sh ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${_LIBEXECDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/include/*.sh ${STAGEDIR}${_LIBEXECDIR}
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
