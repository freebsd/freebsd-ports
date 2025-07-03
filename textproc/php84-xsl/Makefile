CATEGORIES=	textproc

MASTERDIR=	${.CURDIR}/../../lang/php84

PKGNAMESUFFIX=	-xsl

post-patch:
	${REINPLACE_CMD} -e \
		's|#include "../dom/xml_common.h"|#include "ext/dom/xml_common.h"|g' \
		${WRKSRC}/php_xsl.h

.include "${MASTERDIR}/Makefile"
