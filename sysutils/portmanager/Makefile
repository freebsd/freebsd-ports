# New ports collection makefile for:	portmanager
# Date created: 	April 23, 2004
# Whom: 		Michael C. Shultz <ringworm@inbox.lv>
#
# $FreeBSD$
#

PORTNAME=		portmanager
PORTVERSION=		0.1.9
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	portmanager

MAINTAINER=		ringworm@inbox.lv
COMMENT=		FreeBSD port management software

.if !defined(NOPORTDOCS)
BUILD_DEPENDS=		c2html:${PORTSDIR}/textproc/c2html	\
			tidy:${PORTSDIR}/www/tidy
.endif

USE_GMAKE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=		yes

.if !defined(NOPORTDOCS)
PORTDOCS=		docbook.css index.html libPMGR.3.html libPMGR.h.html PMGRrDbCreate.3.html	\
			PMGRrDbCreate.c.html PMGRrDbCreate.h.html PMGRrMakeDescribe.3.html		\
			PMGRrMakeDescribe.c.html PMGRrMakeDescribe.h.html MGrDbArray.3.html		\
			MGrDbArray.c.html MGrDbArray.h.html MGrFileSize.3.html MGrFileSize.c.html	\
			MGrFileSize.h.html MGrFileTime.3.html MGrFileTime.c.html MGrFileTime.h.html	\
			MGrIfFileExist.3.html MGrIfFileExist.c.html MGrIfFileExist.h.html		\
			MGrInStringSwap.3.html MGrInStringSwap.c.html MGrInStringSwap.h.html		\
			MGrIntToString.3.html MGrIntToString.c.html MGrIntToString.h.html		\
			MGsDb.7.html MGsProperty.7.html libMG.3.html libMG.h.html mgmlParse.1.html	\
			mgmlParse.c.html mgmlParse.h.html portmanager.1.html portmanager.c.html 	\
			portmanager.h.html pmStatus.1.html pmStatus.c.html pmStatus.h.html 		\
			pmupgrade.1.html pmupgrade.c.html pmupgrade.h.html
INSTALL_TARGET=		install info

.endif

post-install:
	@${ECHO}	"***************************************************"
	@${ECHO}	"* portmanager commands:                           *"
	@${ECHO}	"*                                                 *"
	@${ECHO}	"* portmanager -h   brief help screen              *"
	@${ECHO}	"*             -s   list status of installed ports *"
	@${ECHO}	"*             -u   upgrade installed ports        *"
	@${ECHO}	"*                                                 *"
	@${ECHO}	"* all feedback is welcome, send to:               *"
	@${ECHO}	"* Michael C. Shultz ringworm@inbox.lv             *"
	@${ECHO}	"***************************************************"
.include <bsd.port.mk>
