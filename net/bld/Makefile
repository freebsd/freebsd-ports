# New ports collection makefile for:   bld
# Date created:        12 October 2004
# Whom:                ob
#
# $FreeBSD$
#

PORTNAME=	bld
PORTVERSION=	0.2.4
CATEGORIES=	net
MASTER_SITES=	http://www.online.redhate.org/bld/

MAINTAINER=	obld@r14.freenix.org
COMMENT=	A blacklisting daemon

USE_RC_SUBR=	yes
MANCOMPRESSED=	yes
GNU_CONFIGURE=	yes

PORTDOCS=	README
MAN5=		bld_whitelist.conf.5 bld_acl.conf.5
MAN8=		bldsubmit.8 bld.8 bldquery.8 bldread.8

SED_SCRIPT=	-e 's|%%PREFIX%%|${PREFIX}|g'
RC_DIR=		${PREFIX}/etc/rc.d
RC_SUFX=	.sh
SED_SCRIPT+=	-e 's|%%RC_SUBR%%|${RC_SUBR}|g' \
		-e 's|%%RC_DIR%%|${RC_DIR}|g' \
		-e 's|%%RC_SUFX%%|${RC_SUFX}|g'

post-build:
		${SED} ${SED_SCRIPT} ${FILESDIR}/bld.sh \
			>${WRKDIR}/bld.sh

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif
	@${INSTALL_SCRIPT} ${WRKDIR}/bld.sh \
		${RC_DIR}/bld${RC_SUFX}
	${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
