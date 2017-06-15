# $FreeBSD$

PORTNAME=	bsdec2-image-upload
PORTVERSION=	1.1.0
CATEGORIES=	net
MASTER_SITES=	http://freebsd-ec2-dist.s3.amazonaws.com/

MAINTAINER=	cperciva@FreeBSD.org
COMMENT=	Tool for creating Amazon EC2 AMIs

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

USES=		ssl tar:tgz uidfix
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

# Install into ${STAGEDIR}${PREFIX}; but the build respects ${DESTDIR} so
# all we need to give is the ${PREFIX}/bin part.
MAKE_ARGS+=	BINDIR=${PREFIX}/bin

PLIST_FILES=	bin/bsdec2-image-upload

.include <bsd.port.mk>
