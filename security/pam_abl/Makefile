# Created by: Petr Rehor <prehor@gmail.com>
# $FreeBSD$

PORTNAME=	pam_abl
PORTVERSION=	0.2.3
CATEGORIES=	security
MASTER_SITES=	SF/pam-abl/pam-abl/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Blacklisting responsible for repeated failed authentication attempts

DEPRECATED=	Newer version requires large number of hacks, not worth the effort
EXPIRATION_DATE=2014-08-24

WRKSRC=		${WRKDIR}/${PORTNAME}

PAMABLDB?=	/var/db/pam_abl

USE_BDB=	42+

SUB_FILES=	pkg-deinstall pkg-message pkg-plist pam_abl.8 190.clean-pam-abl
SUB_LIST=	PAMABLDB=${PAMABLDB}

PKGMESSAGE=	${WRKDIR}/pkg-message
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
PLIST=		${WRKDIR}/pkg-plist

MAN8=		pam_abl.8

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PREFIX} == / || ${PREFIX} == /usr
ETCPREFIX=
.else
ETCPREFIX=	${PREFIX}
.endif
SUB_LIST+=	ETCPREFIX=${ETCPREFIX}

SED_SCRIPT=	-e 's|<db.h>|<${BDB_INCLUDE_DIR}/db.h>|' \
		-e 's|-ldb|-l${BDB_LIB_NAME}|' \
		-e 's|%%PREFIX%%|${PREFIX}|' \
		-e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		-e 's|%%ETCPREFIX%%|${ETCPREFIX}|' \
		-e 's|%%PAMABLDB%%|${PAMABLDB}|'

post-patch:
.for file in Makefile pam_abl.h conf/pam_abl.conf conf/system-auth doc/index.html doc/pam_abl.html tools/Makefile
	@${REINPLACE_CMD} ${SED_SCRIPT} ${WRKSRC}/${file}
.endfor

pre-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS COPYING Copyright NEWS README THANKS conf/system-auth doc/index.html doc/pam_abl.html doc/copying.html doc/style.css
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
	@${MKDIR} ${MAN8PREFIX}/man/man8
	${INSTALL_MAN} ${WRKDIR}/pam_abl.8 ${MAN8PREFIX}/man/man8/
	@${MKDIR} ${PREFIX}/etc/periodic/daily
	${INSTALL_SCRIPT} ${WRKDIR}/190.clean-pam-abl ${PREFIX}/etc/periodic/daily/

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
