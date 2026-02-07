PORTNAME=	safecopy
PORTVERSION=	1.7
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}/

MAINTAINER=	anastasios@mageirias.com
COMMENT=	Safe copying of files and partition
WWW=		https://safecopy.sourceforge.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

PLIST_FILES=	bin/safecopy \
		share/man/man1/safecopy.1.gz

.include <bsd.port.mk>
