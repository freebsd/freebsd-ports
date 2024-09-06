PORTNAME=	pydf
PORTVERSION=	12
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://kassiopeia.juls.savba.sk/~garabik/software/pydf/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	baptiste@bapt.name
COMMENT=	Python implementation of df
WWW=		http://kassiopeia.juls.savba.sk/~garabik/software/pydf/

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Inactive upstream. Does not properly work on FreeBSD
EXPIRATION_DATE=	2024-11-01

SUB_FILES=	pkg-message

USES=		python shebangfix
NO_BUILD=	yes

SHEBANG_FILES=	pydf
PLIST_FILES=	bin/pydf etc/pydfrc.sample share/man/man1/pydf.1.gz

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|%%PYTHON_CMD%%|${PYTHON_CMD}| ; \
		s|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/pydf

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pydf ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/pydfrc ${STAGEDIR}${PREFIX}/etc/pydfrc.sample
	${INSTALL_MAN} ${WRKSRC}/pydf.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
