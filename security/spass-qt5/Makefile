PORTREVISION=	7
PKGNAMESUFFIX=	-qt5

COMMENT=	Secure password generator with a true RNG (Qt5 GUI)

USES=		qmake:no_env qt:5
USE_QT=		buildtools:build core gui widgets

MASTERDIR=	${.CURDIR}/../spass

PLIST_FILES=	bin/spass-qt

# Delete the CLI-only binary which is already provided via security/spass
post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/spass

.include	"${MASTERDIR}/Makefile"
