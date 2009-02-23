# New ports collection makefile for:	duplicity
# Date created:				Wed Jun 11 19:53:46 CEST 2003
# Whom:					Gerhard Häring <gh@ghaering.de>
#
# $FreeBSD$
#

PORTNAME=	duplicity
PORTVERSION=	0.5.09
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	vd@FreeBSD.org
COMMENT=	Untrusted backup using rsync algorithm

LIB_DEPENDS=	rsync.1:${PORTSDIR}/net/librsync
RUN_DEPENDS=	gpg:${PORTSDIR}/security/gnupg \
		${PYTHON_SITELIBDIR}/GnuPGInterface.py:${PORTSDIR}/security/py-gnupg

PEXPECT_DIR=	misc/py-pexpect
OPTIONS=	PEXPECT "Depend on ${PEXPECT_DIR}, needed for ssh backend" On

USE_PYTHON=	2.4+
USE_PYDISTUTILS=yes

MAN1=		duplicity.1 rdiffdir.1

DOCFILES=	CHANGELOG \
		COPYING \
		CVS-README \
		LOG-README \
		README \
		tarfile-LICENSE

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_PEXPECT)
PEXPECT_DEP=	${PYTHON_SITELIBDIR}/pexpect.py:${PORTSDIR}/${PEXPECT_DIR}
BUILD_DEPENDS+=	${PEXPECT_DEP}
RUN_DEPENDS+=	${PEXPECT_DEP}
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for file in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
