CATEGORIES=	textproc

MASTERDIR=	${.CURDIR}/../../lang/php80

PKGNAMESUFFIX=	-xsl

TEST_TARGET=	test

post-patch:
	${REINPLACE_CMD} -e \
		's|#include "../dom/xml_common.h"|#include "ext/dom/xml_common.h"|g' \
		${WRKSRC}/php_xsl.h

.include "${MASTERDIR}/Makefile"
