#! /bin/sh
echo ""
echo "################################################"
echo "#                                              #"
echo "#                IMPORTANT                     #"
echo "#                                              #"
echo "################################################"
echo ""
echo "In order to get this port work properly,"
echo "sox must handle OGG Vorbis files."
echo ""
echo "Now I'll run a quick test for you..."
echo ""
cd ${PORTSDIR}/audio/sox
OGGTEST=`make showconfig|grep VORBIS|awk '{print $1}'`
if test $OGGTEST = 'VORBIS=on'
then
	echo "It seems you have $OGGTEST. Excellent!"
	echo ""
else
	echo "It seems you have $OGGTEST."
	echo "Please go to audio/sox," 
	echo "set WITH_VORBIS=true and recompile"
	echo ""
fi
cd -
