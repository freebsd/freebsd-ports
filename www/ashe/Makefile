# New ports collection makefile for:	ashe
# Version required:	1.1.2
# Date created:		16 October 1995
# Whom:			pst
#
# WARNING WARNING: Requires Motif to compile & link
#
# $Id: Makefile,v 1.2 1995/11/27 04:10:12 asami Exp $
#

DISTNAME=	ashe-1.1.2
CATEGORIES+=	www
MASTER_SITES=	ftp://ftp.cs.rpi.edu/pub/puninj/ASHE/ASHE-1.1.2/src/ \
		ftp://ftp.cs.rpi.edu/pub/puninj/ASHE/ASHE-1.1.2/libcci/ \
		ftp://ftp.cs.rpi.edu/pub/puninj/ASHE/ASHE-1.1.2/libhtmlw/
DISTFILES=	ashe_cci.tar.Z cci.tar.Z libhtmlw.tar.Z

REQUIRES_MOTIF=	yes
NO_WRKSUBDIR=	yes
USE_X11=	yes

.include <bsd.port.mk>
