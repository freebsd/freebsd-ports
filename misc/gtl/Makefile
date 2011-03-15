# New ports collection makefile for:   gtl
# Date created:        05 October 1999
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtl
PORTVERSION=	1.2.3
CATEGORIES=	misc
# The original distribution files are no longer freely
# available from the master_sites
MASTER_SITES=	# http://infosun.fmi.uni-passau.de/GTL/
DISTNAME=	GTL-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ STL-based support for graphs and graph algorithms

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

RESTRICTED=	License forbids redistribution (source or binary)

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	lthack

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/GTL-${PORTVERSION}.tar.gz)
ECHO_MSG=/usr/bin/printf
IGNORE=	\n\
With the release of version 1.0.0 the download policy of GTL has been\n\
changed. GTL can be downloaded free of charge for non-commercial use.\n\
Please follow the steps below to get access to the download archive:\n\
\n\
Send an email to gtl-download@infosun.fmi.uni-passau.de containing the\n\
following information: \n\
- Your Name\n\
- Your Affiliation\n\
- And your email address. Please use your academic address, e.g. .edu, if\n\
  you have. Otherwise your are classified as a "commercial" user.\n\
As soon as possible you will receive an answer from the GTL Team containing\n\
the access code to the download page.\n\
\n\
If you intend to use GTL commercially please send an email to\n\
brandenb@fmi.uni-passau.de.\n
.endif

.include <bsd.port.post.mk>
