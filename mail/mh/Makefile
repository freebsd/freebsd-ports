# New ports collection makefile for:	mh
# Date created:		Oct 4, 1994
# Whom:			pst
#
# $FreeBSD$
#

PORTNAME=	mh
PORTVERSION=	6.8.4
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.ics.uci.edu/pub/mh/tar/
DISTNAME=	${PORTNAME}-6.8.3
EXTRACT_SUFX=	.tar.Z

PATCH_SITES=	ftp://ftp.ics.uci.edu/pub/mh/updates/
PATCHFILES=	MH.6.8.4.Z

MAINTAINER=	pst@FreeBSD.org

FORBIDDEN=	"Buffer overflow in MIME parsing code, exploitable via email. Since mh is no longer actively developed, this bug may not get fixed - consider using the nmh port in ${PORTSDIR}/mail/nmh, which is the successor to mh"

INSTALLS_SHLIB=	yes

MAN1=	ali.1 anno.1 burst.1 comp.1 dist.1 folder.1 forw.1 inc.1 mark.1  \
	mh-chart.1 mh.1 mhl.1 mhook.1 mhmail.1 mhn.1 mhparam.1 mhpath.1  \
	msgchk.1 msh.1 next.1 packf.1 pick.1 prev.1 prompter.1 rcvstore.1 \
	refile.1 repl.1 rmf.1 rmm.1 scan.1 send.1 show.1 slocal.1 sortm.1  \
	vmh.1 whatnow.1 whom.1
MAN5=	mh-alias.5 mh-format.5 mh-mail.5 mh-profile.5 mh-sequence.5 mh-tailor.5
MAN8=	ap.8 conflict.8 dp.8 install-mh.8 post.8 fmtdump.8

.include <bsd.port.mk>
