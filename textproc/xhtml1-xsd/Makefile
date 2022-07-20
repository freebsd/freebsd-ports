PORTNAME=	xhtml1-xsd
PORTVERSION=	200208
CATEGORIES=	textproc
MASTER_SITES=	http://www.w3.org/2002/08/xhtml/
DISTFILES=	xhtml1-frameset.xsd \
		xhtml1-strict.xsd \
		xhtml1-transitional.xsd

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XHTML 1.0 (Second Edition) in XML Schema

NO_WRKSUBDIR=	yes
EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	.
NO_BUILD=	yes

PLIST_FILES=	${DATADIR_REL}/xhtml1-frameset.xsd \
		${DATADIR_REL}/xhtml1-strict.xsd \
		${DATADIR_REL}/xhtml1-transitional.xsd

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PLIST_FILES:S|^${DATADIR_REL}/||} \
		${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
