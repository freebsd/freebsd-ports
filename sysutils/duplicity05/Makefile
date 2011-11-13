# New ports collection makefile for:	duplicity
# Date created:				Wed Jun 11 19:53:46 CEST 2003
# Whom:					Gerhard Häring <gh@ghaering.de>
#
# $FreeBSD$
#

PORTNAME=	duplicity
PORTVERSION=	0.5.20
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://code.launchpad.net/duplicity/0.5-series/${PORTVERSION}/+download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Untrusted backup using rsync algorithm

DEPRECATED=	This version is out of date, and the 0.6.x branch is considered stable
EXPIRATION=	2011-12-31

LIB_DEPENDS=	rsync.1:${PORTSDIR}/net/librsync
RUN_DEPENDS=	gpg:${PORTSDIR}/security/gnupg \
		ncftp>=3.2.2:${PORTSDIR}/ftp/ncftp3

# fetch claims "Moved temporarily" without this - why? (inspired by deskutils/gtg)
FETCH_ARGS=	-pRr

CONFLICTS=	duplicity-0.6.* duplicity-devel-[0-9]*

NO_LATEST_LINK=	yes

USE_PYTHON=	2.4+
USE_PYDISTUTILS=yes
USE_LDCONFIG=	yes
USE_GETTEXT=	yes

MAN1=		duplicity.1 rdiffdir.1

DOCFILES=	CHANGELOG \
		COPYING \
		REPO-README \
		LOG-README \
		README \
		tarfile-LICENSE

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for file in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
