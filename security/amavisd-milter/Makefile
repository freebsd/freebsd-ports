# New ports collection makefile for:	amavisd-milter
# Date created:		2005-06-08
# Whom:			Petr Rehor <prehor@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	amavisd-milter
PORTVERSION=	1.1.1
CATEGORIES=	security mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	prehor@gmail.com
COMMENT=	Milter for amavisd-new

RUN_DEPENDS=	amavisd:${PORTSDIR}/security/amavisd-new

# Shared defaults with security/amavisd-new
AMAVISUSER?=	vscan
AMAVISDIR?=	/var/amavis

GNU_CONFIGURE=	yes
USE_RCORDER=	${PORTNAME}.sh

SUB_FILES=	pkg-message
SUB_LIST=	AMAVISUSER=${AMAVISUSER} \
		AMAVISDIR=${AMAVISDIR}

PORTDOCS=	AUTHORS CHANGES INSTALL LICENSE README TODO

PLIST_SUB=	RC_DIR=${RC_DIR} \
		RC_SUFX=${RC_SUFX}

MAN8=		amavisd-milter.8

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
