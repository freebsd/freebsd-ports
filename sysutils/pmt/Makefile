PORTNAME=	pmt
PORTVERSION=	0.2
CATEGORIES=	sysutils
MASTER_SITES=	http://hansmi.ch/download/pmt/ \
		LOCAL/glarkin

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Small collection of filters which can be added to UNIX pipes
WWW=		https://hansmi.ch/software/pipe-magic-tools

LICENSE=	NONE

USES=		gmake tar:bzip2

PLIST_FILES=	bin/pmt

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=strict-prototypes
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pmt ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.post.mk>
