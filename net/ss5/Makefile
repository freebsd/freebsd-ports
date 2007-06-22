# New ports collection makefile for:   ss5
# Date created:        25 August 2006
# Whom:                Raffaele De Lorenzo  - raffaele.delorenzo@libero.it
#
# $FreeBSD$
#

PORTNAME=	ss5
PORTVERSION=	3.6.2
CATEGORIES=	net security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ss5
DISTNAME=	${PORTNAME}-${PORTVERSION}-1

MAINTAINER=	raffaele.delorenzo@libero.it
COMMENT=	SOCKS v4/v5 application layer gateway with many features

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_OPENLDAP=	yes
USE_RC_SUBR=	${PORTNAME}

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-binpathbase=${PREFIX}/sbin \
		--with-docpathbase=${PREFIX}/share/doc \
		--with-confpathbase=${PREFIX}/etc \
		--with-libpath=${PREFIX}/lib

MAKE_ENV=	DATADIR=${DATADIR} EXAMPLESDIR=${EXAMPLESDIR}
CFLAGS+=	-DLDAP_DEPRECATED

MAN1=		ss5.1
MAN5=		ss5.conf.5 ss5.pam.5 ss5.passwd.5 ss5.peers.5
MANCOMPRESSED=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local,${PREFIX},g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's,/usr/local/etc/opt/ss5,${PREFIX}/etc/ss5,' \
		${WRKSRC}/include/config.h.in

.include <bsd.port.mk>
