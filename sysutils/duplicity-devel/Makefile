# New ports collection makefile for:	duplicity-devel
# Date created:				Fri Jul 10 23:12:20 CEST 2009
# Whom:					Peter Schuller <peter.schuller@infidyne.com>
#
# $FreeBSD$
#

PORTNAME=	duplicity
PORTVERSION=	0.6.03
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMESUFFIX=	-devel

MAINTAINER=	peter.schuller@infidyne.com
COMMENT=	Untrusted backup using rsync algorithm (development/unstable version)

LIB_DEPENDS=	rsync.1:${PORTSDIR}/net/librsync
RUN_DEPENDS=	gpg:${PORTSDIR}/security/gnupg \
		ncftp>=3.2.2:${PORTSDIR}/ftp/ncftp3

CONFLICTS=	duplicity-[0-9]*

USE_PYTHON=	2.4+
USE_PYDISTUTILS=yes
USE_GETTEXT=	yes

MAN1=		duplicity.1 rdiffdir.1

DOCFILES=	CHANGELOG \
		COPYING \
		REPO-README \
		LOG-README \
		README \
		tarfile-LICENSE

.include <bsd.port.pre.mk>

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for file in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
