# Created by: Cy Schubert (Cy.Schubert@uumail.gov.bc.ca)
# $FreeBSD$

PORTNAME=	aide
PORTVERSION=	0.15.1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	SF \
		http://www.cs.tut.fi/~rammer/

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Replacement and extension for Tripwire

LIB_DEPENDS=	libmhash.so:security/mhash

USES=		bison gmake

USE_AUTOTOOLS=	autoconf
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-mhash \
		--with-zlib \
		--mandir=${MANPREFIX}/man \
		--with-config_file=${PREFIX}/etc/aide.conf

LDFLAGS+=	-lpthread -L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include

SUB_FILES=	pkg-message

post-install:
	${INSTALL_DATA} ${FILESDIR}/aide.conf.freebsd ${STAGEDIR}${PREFIX}/etc/aide.conf.sample
	${MKDIR} ${STAGEDIR}/var/db/aide/databases
	${CHMOD} 0700 ${STAGEDIR}/var/db/aide ${STAGEDIR}/var/db/aide/databases

.include <bsd.port.mk>
