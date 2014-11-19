# Created by: Greg Larkin <glarkin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	feather
PORTVERSION=	1.0
CATEGORIES=	sysutils python
MASTER_SITES=	http://www.sourcehosting.net/freebsd/distfiles/ \
		LOCAL/glarkin

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python script for managing tarsnap backups

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yaml>=0:${PORTSDIR}/devel/py-yaml \
		tarsnap>=0:${PORTSDIR}/sysutils/tarsnap

USES=		python
NO_BUILD=	yes
NO_INSTALL=	yes
STRIP=

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/feather ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/feather.yaml.dist ${STAGEDIR}${PREFIX}/etc
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

x-generate-tarball:
	${SETENV} ${FETCH_ENV} ${FETCH_BINARY} -m -o ${PORTNAME}.tar.gz \
		https://github.com/danrue/${PORTNAME}/tarball/master
	target=`${TAR} -tvf ${PORTNAME}.tar.gz | head -n 1`; \
	dir=`${ECHO} $${target} | ${AWK} '{print $$9}' | ${SED} -e 's|/$$||'`; \
	${TAR} -zxf ${PORTNAME}.tar.gz; \
	${RM} ${PORTNAME}.tar.gz; \
	${MV} $${dir} ${PORTNAME}-${PORTVERSION}; \
	${TAR} -zcf ${PORTNAME}-${PORTVERSION}.tar.gz ${PORTNAME}-${PORTVERSION}; \
	${RM} -r ${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
