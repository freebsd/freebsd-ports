PORTREVISION=	0
CATEGORIES=	net python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mjl@luckie.org.nz
COMMENT=	Python bindings for scamper

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libscamperfile.so:${MASTER_PORT}

USES=		python localbase:ldflags
USE_PYTHON=	flavors
CONFIGURE_ARGS=	--with-python

PORTSCOUT=	ignore:1

SLAVE_PORT=	yes
MASTERDIR=	${.CURDIR}/../scamper

PLIST=		${.CURDIR}/pkg-plist
BUILD_WRKSRC=	${WRKSRC}/lib/python
INSTALL_WRKSRC=	${BUILD_WRKSRC}

PLIST_FILES=	${PYTHONPREFIX_SITELIBDIR:S,^${PREFIX}/,,}/scamper.a \
		${PYTHONPREFIX_SITELIBDIR:S,^${PREFIX}/,,}/scamper.so \
		${PYTHONPREFIX_SITELIBDIR:S,^${PREFIX}/,,}/scamper.pyi

post-patch:
	@${REINPLACE_CMD} \
		-e 's/$$(scamper_la_DEPENDENCIES)//' \
		-e 's,../libscamperfile/libscamperfile.la,-lscamperfile,' \
		-e 's,../libscamperctrl/libscamperctrl.la,-lscamperctrl,' \
		${BUILD_WRKSRC}/Makefile.in

.include "${MASTERDIR}/Makefile"
