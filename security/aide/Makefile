# Created by: Cy Schubert (Cy.Schubert@uumail.gov.bc.ca)
# $FreeBSD$

PORTNAME=	aide
PORTVERSION=	0.16.1
CATEGORIES=	security
MASTER_SITES=	https://github.com/aide/aide/releases/download/v${PORTVERSION}/

MAINTAINER=	cy@FreeBSD.org
COMMENT=	File and directory integrity checker

LIB_DEPENDS=	libmhash.so:security/mhash \
		libpcre.so:devel/pcre

USES=		autoreconf bison gmake localbase

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-mhash \
		--with-zlib \
		--mandir=${MANPREFIX}/man \
		--with-config_file=${PREFIX}/etc/aide.conf
CONFIGURE_ENV=	YACC="bison -y"

LDFLAGS+=	-lpthread

SUB_FILES=	pkg-message

post-install:
	${INSTALL_DATA} ${FILESDIR}/aide.conf.freebsd ${STAGEDIR}${PREFIX}/etc/aide.conf.sample
	${MKDIR} ${STAGEDIR}/var/db/aide/databases
	${CHMOD} 0700 ${STAGEDIR}/var/db/aide ${STAGEDIR}/var/db/aide/databases

.include <bsd.port.mk>
