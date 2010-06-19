# New ports collection makefile for:	qmail-activedir
# Date created:		2005-11-08
# Whom:			Jean Milanez Melo <jmelo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	qmail-activedir
PORTVERSION=	0.16
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://fo2k.com/qmail-activedir/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Programs to allow qmail to authenticate users through a MS ad

USE_QMAIL_RUN=	yes
SUB_FILES=	pkg-message
SUB_LIST+=	QMAIL_PREFIX=${QMAIL_PREFIX}
USE_OPENLDAP=	yes

BINARIES=	checkadpassword qmail-adgetpw create_alias_files

CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib -Wall -lldap

PLIST_FILES=	bin/checkadpassword \
		bin/create_alias_files \
		bin/qmail-adgetpw

PORTDOCS=	INSTALL README

.if defined(WITH_OPENLDAP_VER)
WANT_OPENLDAP_VER=	${WITH_OPENLDAP_VER}
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,/var/qmail,${QMAIL_PREFIX},g' \
			  -e 's,\(#define AD_USE_GC\) 1,\1 0,' \
			  -e 's,\(#define AD_ONLY_USE_SSL\) 1,\1 0,' \
		${WRKSRC}/ad_func.h

do-build:
.for prog in ${BINARIES}
	${CC} ${CFLAGS} ${WRKSRC}/${prog}.c ${WRKSRC}/ad_func.c -o \
		${WRKSRC}/${prog}
.endfor

do-install:
.for prog in ${BINARIES}
	${INSTALL_PROGRAM} ${WRKSRC}/${prog} ${PREFIX}/bin/
.endfor
	${CHMOD} 700 ${PREFIX}/bin/checkadpassword \
		     ${PREFIX}/bin/create_alias_files
	${CHMOD} 711 ${PREFIX}/bin/qmail-adgetpw
	${CHOWN} root:qmail ${PREFIX}/bin/qmail-adgetpw
	${CHOWN} root:wheel ${PREFIX}/bin/create_alias_files
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
