# New ports collection makefile for:	duplicity
# Date created:				Wed Jun 11 19:53:46 CEST 2003
# Whom:					Gerhard Häring <gh@ghaering.de>
#
# $FreeBSD$
#

PORTNAME=	duplicity
PORTVERSION=	0.6.17
CATEGORIES=	sysutils
MASTER_SITES=	http://launchpad.net/duplicity/0.6-series/${PORTVERSION}/+download/

MAINTAINER=	freebsd@beardz.net
COMMENT=	Backup tool that uses rsync and GnuPG

LIB_DEPENDS=	rsync.1:${PORTSDIR}/net/librsync
RUN_DEPENDS=	gpg:${PORTSDIR}/security/gnupg \
		ncftp>=3.2.2:${PORTSDIR}/ftp/ncftp3 \
		lftp>=3.7.15:${PORTSDIR}/ftp/lftp

OPTIONS=	NLS "National Language Support" on

# fetch claims "Moved temporarily" without this - why? (inspired by deskutils/gtg)
FETCH_ARGS=	-pRr

CONFLICTS=	duplicity-0.5.* duplicity-devel-[0-9]*

USE_PYTHON=	2.5+
USE_PYDISTUTILS=yes
USE_LDCONFIG=	yes

.include "bsd.port.options.mk"

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "

post-patch:
	@${REINPLACE_CMD} -e '54,63d' \
		${WRKSRC}/setup.py
.endif

MAN1=		duplicity.1 rdiffdir.1

DOCFILES=	COPYING \
		README \
		README-REPO \
		README-LOG \
		tarfile-LICENSE \
		tarfile-CHANGES \
		CHANGELOG

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for file in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
