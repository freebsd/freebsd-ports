cd /usr/ports/math/lean4/work/lean4-`make -V PORTVERSION`/tests/lean/run
export PATH=/usr/ports/math/lean4/work/.build/stage1/bin:$PATH

for t in letToHave.lean 983.lean ExprLens.lean try_heartbeats.lean collectLooseBVars.lean whereCmd.lean async_select_channel.lean; do
	echo "==> Running test: $t"
	result=$(bash test_single.sh $t 2>&1; echo "exit=$?")
	echo "... output for $t: $result"

	if [ "$result" == "exit=0" ]; then
		echo "<== Test $t passed."
	else
		echo "<== Test $t failed. Output: $result"
	fi
done
