# Created by: Colin Percival

PORTNAME=	tarsnap
PORTVERSION=	1.0.40
CATEGORIES=	sysutils
MASTER_SITES=	http://www.tarsnap.com/download-http/
DISTNAME=	${PORTNAME}-autoconf-${PORTVERSION}

MAINTAINER=	cperciva@tarsnap.com
COMMENT=	Online encrypted backup service (client)

LICENSE=	tarsnap
LICENSE_NAME=	tarsnap

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="-I${OPENSSLINC} ${CFLAGS}" \
		LDFLAGS="-L${OPENSSLLIB} ${LDFLAGS}"
CONFIGURE_ARGS=	--with-bash-completion-dir=${PREFIX}/etc/bash_completion.d/

USES=		gmake tar:tgz ssl

.include <bsd.port.pre.mk>

# safety check to ensure that we don't violate the license
.if exists(${PATCHDIR})
# Converted from RESTRICTED
LICENSE_TEXT=	license only allows redistribution and use of unmodified source and binaries
LICENSE_PERMS=	auto-accept
.else
# Converted from LEGAL_TEXT
LICENSE_TEXT=	license restricts redistribution of source and binaries
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept
.endif

.include <bsd.port.post.mk>
