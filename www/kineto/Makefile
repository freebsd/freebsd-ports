PORTNAME=	kineto
DISTVERSION=	g20250122
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	corey@electrickite.org
COMMENT=	HTTP to Gemini proxy
WWW=		https://git.sr.ht/~sircmpwn/kineto/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		go:modules
USE_GITHUB=	nodefault
GH_TUPLE=	golang:net:v0.57.0:golang_net/vendor/golang.org/x/net \
		golang:text:v0.40.0:golang_text/vendor/golang.org/x/text

SH_COMMIT=	1f4e0667
# Additional distfiles to fetch from https://git.sr.ht
_SRHT_TUPLE=	sircmpwn:${PORTNAME}:${SH_COMMIT}:"" \
		adnano:go-gemini:v0.2.5:vendor/git.sr.ht/~adnano/go-gemini \
		sircmpwn:getopt:v1.0.0:vendor/git.sr.ht/~sircmpwn/getopt

USE_RC_SUBR=	${PORTNAME}

WRKSRC=		${WRKDIR}/${PORTNAME}-${SH_COMMIT}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.pre.mk>

.for account project tag subdir in ${_SRHT_TUPLE:S/:/ /g}
MASTER_SITES+=	https://git.sr.ht/~${account}/${project}/archive/${tag}${EXTRACT_SUFX}?dummy=/:${account}_${project:S/-/_/g}
DISTFILES+=	${account}-${project}-${tag}_SRHT0${EXTRACT_SUFX}:${account}_${project:S/-/_/g}
.endfor

post-extract:
.for account project tag subdir in ${_SRHT_TUPLE:S/:/ /g:[5..-1]}
	@${MKDIR} ${WRKSRC}/${subdir:H}
	@${MV} ${WRKDIR}/${project}-${tag} ${WRKSRC}/${subdir}
.endfor

.include <bsd.port.post.mk>
