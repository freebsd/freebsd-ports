#Macro from pwsh port
NUGET_DISTSUBDIR?=	nuget
EXTRACT_ONLY?=		${_DISTFILES:N${_NUPKG_PREFIX}*.nupkg}
NUGET_GROUPS?=		NUGET

NUGET_GROUP_NUGET=	NUGET

NUGET_NUGET_BASEURL=	https://api.nuget.org/v3-flatcontainer/
NUGET_NUGET_PKGPATH=	%%LCNAME%%/%%LCVERSION%%/%%NUPKG%%

_NUPKG_PREFIX=	${NUGET_DISTSUBDIR:C/.+/&\//}
_NUGET_MKDIR=	${NUGET_DISTSUBDIR:C/.+/${MKDIR} ${DISTDIR}\/& \&\&/}
_NUGET_FULL=	${NUGET_GROUPS:@g@${NUGET_GROUP_${g}:@r@\
		${NUPKG_${g}:@p@${r}:${p}@}@}@}

_NUGET_FETCH=	${_NUGET_MKDIR}cd ${DISTDIR}/${NUGET_DISTSUBDIR} && \
		${_NUGET_FULL:@s@${v::=${s:S/:/ /g}}\
		${n::=${v:[2]:tl}.${v:[3]:tl}.nupkg}\
		${p::=${NUGET_${v:[1]}_BASEURL}${NUGET_${v:[1]}_PKGPATH}}\
		${p::=${p:S/%%LCNAME%%/${v:[2]:tl}/g}}\
		${p::=${p:S/%%LCVERSION%%/${v:[3]:tl}/g}}\
		${p::=${p:S/%%NAME%%/${v:[2]}/g}}\
		${p::=${p:S/%%VERSION%%/${v:[3]}/g}}\
		${p::=${p:S/%%NUPKG%%/${n}/g}}\
		test -f ${n} || ${FETCH_CMD} -o ${n} "${p}";@}

DISTFILES+=	${NUGET_GROUPS:@g@${NUPKG_${g}:tl:@p@\
		${_NUPKG_PREFIX}${p:S/:/./}.nupkg@}@:O:u}


