PORTNAME=	hw-probe
PORTVERSION=	1.6.4
CATEGORIES=	sysutils perl5

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Probe for hardware, check operability, and find drivers

LICENSE=	LGPL21+ BSD4CLAUSE
LICENSE_COMB=	dual

RUN_DEPENDS=	curl:ftp/curl \
		hwstat:sysutils/hwstat \
		lsblk:sysutils/lsblk \
		smartctl:sysutils/smartmontools

USE_GITHUB=	yes
GH_ACCOUNT=	linuxhw

USES=		perl5
USE_PERL5=	run
MAKE_ARGS=	prefix=${PREFIX}
NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	NEWS.md README.md

.include <bsd.port.pre.mk>

.if ${ARCH} == i386 || ${ARCH} == amd64
RUN_DEPENDS+=	dmidecode:sysutils/dmidecode \
		lscpu:sysutils/lscpu
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/s x | grep/grep -l/; s/ | grep -v grep//' \
		${WRKSRC}/${PORTNAME}.pl

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
