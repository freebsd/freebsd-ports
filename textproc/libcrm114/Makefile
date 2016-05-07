# Created by: Martin Schuette <info@mschuette.name>
# $FreeBSD$

PORTNAME=	libcrm114
PORTVERSION=	20100726
CATEGORIES=	textproc
MASTER_SITES=	http://crm114.sourceforge.net/tarballs/

MAINTAINER=	info@mschuette.name
COMMENT=	CRM114 C-callable Library

LIB_DEPENDS=	libtre.so:textproc/libtre

LICENSE=	LGPL3

USES=		gmake
USE_LDCONFIG=	yes

# pass stuff to gmake
CFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	-DNO_LOGL -DDO_INLINES
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_JOBS_UNSAFE=yes

PLIST_FILES=	lib/libcrm114.so \
		lib/libcrm114.so.0 \
		include/crm114_config.h \
		include/crm114_lib.h \
		include/crm114_structs.h \
		include/crm114_sysincludes.h \
		share/doc/libcrm114/HOWTO.txt \
		share/doc/libcrm114/simple_demo.c

.include <bsd.port.mk>
