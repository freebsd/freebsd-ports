# Makefile for:		slirp
# Version required:	alpha
# Date created:		05 April 1995
# Whom:			jkh
#
# $Id: Makefile,v 1.2 1995/04/01 12:47:57 jkh Exp $
#

# This is ALPHA software, but I think it's of sufficient interest to enough
# people to bring it over now.  I hope that both patches an go away soon
# enough..  Yes, I know that it currently produces some weird error messages.
# They're harmless as far as the operation of slirp is concerned.  I also
# know that the "manpage" is cheesy - it's better than nothing! :-)

DISTNAME=	slirp
MASTER_SITES=	ftp://blitzen.canberra.edu.au/pub/slirp/ ftp://freedom.wit.com/misc4/danjo/SLiRP/
CATEGORIES+=	networking
WRKSRC=		${WRKDIR}/slurp/src
MAKE_FLAGS=	freebsd -f

.include <bsd.port.mk>
