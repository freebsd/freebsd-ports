# New ports collection makefile for:	duplicity
# Date created:				Wed Jun 11 19:53:46 CEST 2003
# Whom:					Gerhard Häring <gh@ghaering.de>
#
# $FreeBSD$
#

PORTNAME=	duplicity
PORTVERSION=	0.6.19
CATEGORIES=	sysutils
MASTER_SITES=	http://launchpad.net/duplicity/0.6-series/${PORTVERSION}/+download/

MAINTAINER=	jase@FreeBSD.org
COMMENT=	Backup tool that uses librsync and GnuPG

LIB_DEPENDS=	rsync:${PORTSDIR}/net/librsync
RUN_DEPENDS=	gpg:${PORTSDIR}/security/gnupg \
		ncftp>=3.2.2:${PORTSDIR}/ftp/ncftp3 \
		lftp>=3.7.15:${PORTSDIR}/ftp/lftp \
		${PYTHON_PKGNAMEPREFIX}paramiko>=1.7.7.1:${PORTSDIR}/security/py-paramiko \
		${PYTHON_PKGNAMEPREFIX}boto>=1.6b:${PORTSDIR}/devel/py-boto

FETCH_ARGS=	-pRr

CONFLICTS=	duplicity-0.5.* duplicity-devel-[0-9]*

USE_PYTHON=	2.5+
USE_PYDISTUTILS=yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	NLS DOCS

.include "bsd.port.options.mk"

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "

post-patch:
	@${REINPLACE_CMD} -e '54,62d' \
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
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for file in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
