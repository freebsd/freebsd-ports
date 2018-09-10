
BEGIN { in_licence = 0 }

{
  if (!in_licence && $2 == "LICENSE") {
    in_licence = 1
    print prev_line
    del_count = 1
  } else if (in_licence) {
    if ($1 == "############################################################################") {
      del_count = del_count+1
      if (del_count > 2)
        in_licence = 0
    }
  }

  if (in_licence)
    print $0

  prev_line = $0
}
