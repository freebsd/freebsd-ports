#
#	Makefile for ports/mail/elm (FreeBSD)
#	$Id: $
#

# Distribution stuff
DISTNAME=	elm2.4
EXTRACT_SUFX=	.tar.Z
MASTER_SITES=	ftp://dsinc.myxa.com/pub/elm/

# working directory
WRKDIR=		work
NO_WRKSUBDIR=	is_set

# Interactive
IS_INTERACTIVE=	is_set

# Packaging
NO_PACKAGE=	is_set
# PKGDIR=	pkg

pre-configure:
	@echo "===> Running pre-configure target for ${DISTNAME}"
	@sh ${SCRIPTDIR}/preconf ${PORTSDIR} ${.CURDIR} ${WRKSRC}

.include <bsd.port.mk>
