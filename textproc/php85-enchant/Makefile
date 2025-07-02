CATEGORIES=	textproc

MASTERDIR=	${.CURDIR}/../../lang/php85

PKGNAMESUFFIX=	-enchant

post-patch:
	${REINPLACE_CMD} -e \
		's|#include "../spl/spl_exceptions.h"|#include "ext/spl/spl_exceptions.h"|g' \
		${WRKSRC}/enchant.c

.include "${MASTERDIR}/Makefile"
