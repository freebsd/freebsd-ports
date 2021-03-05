# $FreeBSD$

PORTNAME=	bsdec2-image-upload
PORTVERSION=	1.4.1
CATEGORIES=	net
MASTER_SITES=	http://freebsd-ec2-dist.s3.amazonaws.com/

MAINTAINER=	cperciva@FreeBSD.org
COMMENT=	Tool for creating Amazon EC2 AMIs

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

USES=		compiler ssl tar:tgz uidfix
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

# Install into ${STAGEDIR}${PREFIX}
MAKE_ARGS+=     BINDIR=${STAGEDIR}${PREFIX}/bin

PLIST_FILES=	bin/bsdec2-image-upload

.include <bsd.port.mk>
