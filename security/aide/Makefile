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

LIB_DEPENDS=	libmhash.so:${PORTSDIR}/security/mhash
USES=		bison gmake

.include <bsd.port.pre.mk>

USE_AUTOTOOLS=	autoconf
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-mhash \
		--with-zlib \
		--mandir=${MANPREFIX}/man \
		--with-config_file=${PREFIX}/etc/aide.conf

LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CFLAGS+=	-I${LOCALBASE}/include

SUB_FILES=	pkg-message

post-install:
	@${INSTALL_DATA} ${FILESDIR}/aide.conf.freebsd ${STAGEDIR}${PREFIX}/etc/aide.conf.sample
	@if [ ! -f ${STAGEDOIR}${PREFIX}/etc/aide.conf ]; then \
		${INSTALL_DATA} ${FILESDIR}/aide.conf.freebsd ${STAGEDIR}${PREFIX}/etc/aide.conf ; \
	fi

.include <bsd.port.post.mk>
